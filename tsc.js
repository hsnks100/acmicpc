function append(str1, str2) {
    return str1 + str2;
}
var str = append('hello', ' Typescript!!');
var Greeter = (function () {
    function Greeter(message) {
        this.greeting = message;
    }
    Greeter.prototype.greet = function () {
        return "Hello, " + this.greeting;
    };
    return Greeter;
})();
var greeter = new Greeter("world");
console.log(str);
