var Stack = /** @class */ (function () {
    function Stack() {
        this.count = 0;
        this.storage = [];
    }
    Stack.prototype.push = function (val) {
        this.storage[this.count] = val;
        this.count++;
    };
    Stack.prototype.pop = function () {
        if (this.count == 0) {
            return undefined;
        }
        this.count--;
        var val = this.storage[this.count];
        delete this.storage[this.count];
        return val;
    };
    Stack.prototype.size = function () {
        return this.count;
    };
    Stack.prototype.peek = function () {
        return this.storage[this.count - 1];
    };
    Stack.prototype.isEmpty = function () {
        return this.count == 0;
    };
    return Stack;
}());
var mystack = new Stack();
mystack.push(1);
mystack.push(2);
console.log(mystack.isEmpty());
console.log(mystack.peek());
console.log(mystack.pop());
console.log(mystack.pop());
console.log(mystack.size());
console.log(mystack.peek());
console.log(mystack.pop());
console.log(mystack.peek());
console.log(mystack.isEmpty());
