class Stack<T> {
    count: number;
    storage: Array<T>;

    constructor() {
        this.count = 0;
        this.storage = [];
    }

    push(val: T) {
        this.storage[this.count] = val;
        this.count++;
    }

    pop() {
        if (this.count == 0) {
            return undefined;
        }

        this.count--;
        let val = this.storage[this.count];
        delete this.storage[this.count];
        return val;
    }

    size() {
        return this.count;
    }

    peek() {
        return this.storage[this.count - 1];
    }

    isEmpty() {
        return this.count == 0;
    }
}

const mystack = new Stack<number>();
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