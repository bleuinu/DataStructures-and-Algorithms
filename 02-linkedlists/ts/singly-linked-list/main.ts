class ListNode<T> {
    public data: T | null;
    public next: ListNode<T> | null;

    constructor(data: T | null, next: ListNode<T> | null) {
        this.data = data;
        this.next = next;
    }
}

class SinglyLinkedList<T> {
    public dhead: ListNode<T>;
    public size: number;

    constructor() {
        this.dhead = new ListNode<T>(null, null);
        this.size = 0;
    }

    getSize(): number {
        return this.size;
    }

    isEmpty(): boolean {
        return this.size == 0;
    }

    front(): T | null {
        if (this.isEmpty()) {
            return null;
        }

        return this.dhead.next?.data as T;
    }

    back(): T | null {
        if (this.isEmpty()) {
            return null;
        }

        let curr = this.dhead;
        while (curr.next != null) {
            curr = curr.next;
        }

        return curr.data;
    }

    /* pos: 1-based */
    value_at(pos: number): T | null {
        if (this.isEmpty()) {
            console.log("List is empty..");
            return null;
        }

        if (pos <= 0 || pos > this.size) {
            console.log("Invalid value... position:", pos);
            return null;
        }

        let curr = this.dhead;
        while (pos && curr.next) {
            curr = curr.next;
            --pos;
        }

        return curr.data;
    }

    push_front(data: T): void {
        let newnode = new ListNode<T>(data, this.dhead.next);
        this.dhead.next = newnode;
        this.size++;
    }

    push_back(data: T): null | undefined {
        if (this.isEmpty()) {
            this.push_front(data);
            return null;
        }

        let curr = this.dhead;

        while (curr.next != null) {
            curr = curr.next;
        }
        let newnode = new ListNode<T>(data, null);
        curr.next = newnode;
        this.size++;
    }

    pop_front(): T | null {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }

        let curr = this.dhead.next;
        if (this.size == 1) {
            this.dhead.next = null;
            this.size--;
            return curr?.data as T;
        } else {
            let temp = this.dhead.next;
            this.dhead.next = temp?.next as ListNode<T>;
            let data = temp?.data;
            temp = null;
            this.size--;
            return data as T;
        }
    }

    pop_back(): T | null {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }

        if (this.size == 1) {
            return this.pop_front();
        }

        let curr = this.dhead;
        while (curr.next?.next) {
            curr = curr.next;
        }

        let data = curr.next?.data;
        curr.next = null;
        this.size--;
        return data as T;
    }

    /* pos: 1-based */
    insert(data: T, pos: number): null | undefined {
        if (pos <= 0 || pos > this.size + 1) {
            console.log("Invalid value... position:", pos);
            return null;
        }

        if (pos == 1) {
            this.push_front(data);
        } else if (pos == this.size + 1) {
            this.push_back(data);
        } else {
            let curr = this.dhead;
            --pos;

            while (pos && curr.next) {
                curr = curr.next;
                --pos;
            }

            let newnode = new ListNode<T>(data, curr.next);
            curr.next = newnode;
            this.size++;
        }
    }

    /* pos = 1-based */
    erase(pos: number): T | null {
        if (pos <= 0 || pos > this.size) {
            console.log("Invalid value... position:", pos);
            return null;
        }

        if (pos == 1) {
            return this.pop_front();
        }

        if (pos == this.size) {
            return this.pop_back();
        }

        --pos;
        let curr = this.dhead;
        while (pos && curr.next) {
            curr = curr.next;
            --pos;
        }

        let data = curr.next?.data;
        curr.next = curr.next?.next as ListNode<T>;
        this.size--;

        return data as T;
    }

    remove_value(data: T): boolean {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return false;
        }

        let curr = this.dhead;

        while (curr.next) {
            if (curr.next.data == data) {
                let temp = curr.next;
                curr.next = curr.next.next;
                temp.next = null;
                this.size--;
                return true;
            }
            curr = curr.next;
        }

        return false;
    }

    reverse(): void {
        type node = ListNode<T> | null;
        let prev: node = null;
        let curr: node = this.dhead.next;

        while (curr != null) {
            let next: node = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        this.dhead.next = prev;
    }

    print(): null | undefined {
        if (this.isEmpty()) {
            return null;
        }

        let curr = this.dhead.next;
        let output = '';
        let front_back = `f:${this.front()}, b:${this.back()})`;
        while (curr) {
            output += `${curr.data} `;
            curr = curr.next;
        }
        output += `(size:${this.getSize()}, ${front_back}`;
        console.log(output);
    }
}

import { readlink } from 'fs';
const prompt = require("prompt-sync")({ sigint: true });

let list = new SinglyLinkedList<number>();

console.log("------- Operations ------");
console.log(" 1. push_back      2. push_front");
console.log(" 3. pop_back       4. pop_front");
console.log(" 5. insert");
console.log(" 6. erase          7. remove_value");
console.log(" 8. front          9. back");
console.log("10. size          11. isEmpty");
console.log("12. print         13. reverse");
console.log("14. valueAt        0. Exit");

let isRunning: boolean = true;
while (isRunning) {
    const answer = prompt("> ");

    switch (answer) {
        case "1": {
            let data = prompt("push back: ");
            list.push_back(parseInt(data));
            list.print();
            break;
        }
        case "2": {
            let data = prompt("push front: ");
            list.push_front(parseInt(data));
            list.print();
            break;
        }
        case "3": {
            list.pop_back();
            list.print();
            break;
        }
        case "4": {
            list.pop_front();
            list.print();
            break;
        }
        case "5": {
            let data = prompt("Insert data: ");
            let pos = prompt("at position (1-based): ");
            list.insert(data, pos);
            list.print();
            break;
        }
        case "6": {
            let pos = prompt("Erase a value at position (1-based): ");
            list.erase(pos);
            list.print();
            break;
        }
        case "7": {
            let data = prompt("Remove a value: ");
            list.remove_value(data);
            list.print();
            break;
        }
        case "8": {
            console.log("Front:", list.front());
            break;
        }
        case "9": {
            console.log("Back:", list.back());
            break;
        }
        case "10": {
            console.log("Size:", list.getSize());
            break;
        }
        case "11": {
            if(list.isEmpty()) {
                console.log("List is empty.");
            } else {
                console.log("List is not empty.");
            }
             break;
        }
        case "12": {
            list.print();
            break;
        }
        case "13": {
            list.reverse();
            list.print();
            break;
        }
        case "14": {
            let pos = prompt("Value at position (1-based): ");
            console.log(list.value_at(pos));
            break;
        }
        case "0": {
            console.log("Bye!");
            isRunning = false;
        }
    }
}