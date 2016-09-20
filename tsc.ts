
function append(str1:string,
                str2:string):string{
                    return str1 + str2;
                }


var str:string = append('hello',

                        ' Typescript!!');



class Greeter{
      greeting:string;
      constructor(message: string){
                           this.greeting = message;
      }

      greet(){
        return "Hello, " + this.greeting;
      }


}

var greeter = new Greeter("world");

console.log(str);