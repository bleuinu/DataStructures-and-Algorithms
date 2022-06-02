class ListNode<T> {
    public data: T;
    public next: ListNode<T> | undefined;

    constructor(data: T) {
        this.data = data;
        this.next = undefined;
    }
}

class Stack<T> {
    private top: ListNode<T> | undefined;
    private size: number;

    constructor() {
        this.top = undefined;
        this.size = 0;
    }

    push(data: T): void {
        let newNode: ListNode<T> = new ListNode<T>(data);
        newNode.next = this.top;
        this.top = newNode;
        this.size++;
    }

    pop(): void {
        if(this.isEmpty()) {
            console.log("Stack is empty...");
            return;
        }

        this.top = this.top?.next;
        this.size--;
    }

    peek(): T | undefined {
        if(this.isEmpty()) {
            console.log("Stack is empty...");
            return;
        } else {
            return this.top?.data;
        }
    }

    isEmpty(): boolean {
        return this.size == 0;
    }
    
    print(): void {
        let curr: ListNode<T> | undefined = this.top;
        let output = "";
        while(curr) {
            output += `${curr.data} `;
            curr = curr.next;
        }

        console.log(output);
    }
}

import { readlink } from 'fs';
const prompt = require("prompt-sync")({ sigint: true });

console.log("------- Operations ------");
console.log(" 1. push      2. pop");
console.log(" 3. peek      4. isEmpty");
console.log(" 5. print     0. quit");

let stack = new Stack<number>();


let isRunning: boolean = true;
while (isRunning) {
    const answer = prompt("> ");

    switch(answer) {
        case "1": {
            const data = prompt("push data: ");
            stack.push(data);
            break; 
        }
        case "2": {
            stack.pop();
            console.log(`${stack.peek()} popped from the stack.`);
            break;
        }
        case "3": {
            console.log("Top:", stack.peek())
            break;
        }
        case "4": {
            if(stack.isEmpty()) {
                console.log("Stack is empty.");
            } else {
                console.log("Stack is NOT empty.");
            }
            break;
        }
        case "5": {
            stack.print();
            break;
        }
        default: {
            isRunning = false;
        }
    }
}