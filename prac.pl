use Data::Dumper;
my@inp;
push@inp,split while<>;

@notPrime;
for$i(2..1000){
  if($notPrime[$i] == 0){
    my $mul = 2;
    until(0){
      $notPrime[$i*$mul] = 1;
      $mul++; 
      if($i*$mul > 1000){
        last;
      } 
    }
  } 
}

$n = shift@inp;
@odds;@evens;
for(1..$n){
  my $a = shift@inp;
  if($a % 2 == 1){
    push @odds, $a;
  }
  else{
    push @evens, $a;
  }
}

for$i(@odds){ 
  for$j(@evens){
    unless($notPrime[$i + $j]){
      push @{$graph->[$i]}, $j;
    }
  }
}

# s 가 다른것을 선택할 수 있는지여부
sub dfs {
  (my $s) = @_;

  if(

}
print Dumper(\$graph);
