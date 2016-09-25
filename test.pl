#!/usr/bin/perl

use local::lib;
use Data::Dumper;
use HTTP::Tiny; 
use Mojo::DOM; 
use LWP::Simple;

my $lastNo;
unless(-e "lastno.txt"){
  $lastNo = 0; 
}
else{
  open FH, "<", "lastno.txt" or die "$!\n";
  $lastNo = int<FH>;
  close FH;
}
print "lastNo = $lastNo\n";
#exit;
my $url = 'http://uwcms.pusan.ac.kr/user/indexSub.action?codyMenuSeq=21712&siteId=cse';
my $res = HTTP::Tiny->new->get($url); 
my $html = $res->{content}; 
my $dom = Mojo::DOM->new($html); 
my $maxNo = -1e9;
print "send list\n";
$lastNo = 98;
for my $post ( $dom->find('table[summary="게시판리스트"]>tbody>tr')->each ) { 
  my $title = $post->at('[class="title"]')->all_text;
  my $no = $post->at('[class="no"]')->all_text;
  my $ahref = 'http://uwcms.pusan.ac.kr/user/' . $post->at('[class="title"]>a')->attr('href');
  $title =~ s/\s+$//g;
  $title =~ s/^\s+//g;
  $title =~ s/\n.+/\1/g;
  
  $maxNo = $no if $maxNo < $no;
  #print "[$no]$title \n $ahref\n";
  $title .=  $ahref;
  if($no > $lastNo){ 
    my $url = "http://mspeeder.kr/sms_sender2.php?action=go&smsType=S&subject=제목&msg=$title&rphone=01073177595&sphone1=010&sphone2=7317&sphone3=7595&nointeractive=1&repeatNum=1&repeatTime=15";
    my $content = get($url);
    #print $content;

    #print "$title\n";

  }
}
print "-----------\n";

if($maxNo > $lastNo){
  print "LastNo was updated\n";
  open FH, ">", "lastno.txt" or die "$!\n";
  print FH $maxNo;
  close FH;
}



