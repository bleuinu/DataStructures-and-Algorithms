class ListNode<T> {
    public data: T | null;
    public next: ListNode<T> | null;
    public prev: ListNode<T> | null;

    constructor(data: T | null) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList<T> {
    public dhead: ListNode<T>;
    public dtail: ListNode<T>;
    public size: number;

    constructor() {
        this.dhead = new ListNode<T>(null);
        this.dtail = new ListNode<T>(null);
        this.dhead.next = this.dtail;
        this.dtail.prev = this.dhead;
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

        return this.dtail.prev?.data as T;
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
        let newnode = new ListNode<T>(data);
        (this.dhead.next as ListNode<T>).prev = newnode;
        newnode.prev = this.dhead;
        newnode.next = this.dhead.next;
        this.dhead.next = newnode;
        this.size++;
    }

    push_back(data: T): void {
        let newnode = new ListNode<T>(data);
        (this.dtail.prev as ListNode<T>).next = newnode;
        newnode.prev = this.dtail.prev;
        newnode.next = this.dtail;
        this.dtail.prev = newnode;
        this.size++;
    }

    pop_front(): T | null {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }

        let temp = this.dhead.next as ListNode<T>;
        (temp.prev as ListNode<T>).next = temp.next;
        (temp.next as ListNode<T>).prev = temp.prev;
        this.size--;
        return temp.data;
    }

    pop_back(): T | null {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }

        let curr = this.dtail.prev as ListNode<T>;
        this.dtail.prev = curr.prev;
        (curr.prev as ListNode<T>).next = this.dtail;
        this.size--;
        return curr.data;
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

            while (pos && curr.next) {
                curr = curr.next;
                --pos;
            }

            let newnode = new ListNode<T>(data);
            newnode.prev = curr.prev;
            newnode.next = curr;
            (curr.prev as ListNode<T>).next = newnode;
            curr.prev = newnode;
            this.size++;
        }
    }

    /* pos = 1-based */
    erase(pos: number): T | null {
        if (pos <= 0 || pos > this.size) {
            console.log("Invalid value... position:", pos);
            return null;
        }

        let curr = this.dhead;
        while (pos && curr.next) {
            curr = curr.next;
            --pos;
        }

        let data = curr.data;
        (curr.prev as ListNode<T>).next = curr.next;
        (curr.next as ListNode<T>).prev = curr.prev;
        this.size--;

        return data;
    }

    remove_value(data: T): boolean {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return false;
        }

        let curr = this.dhead.next;

        while (curr != this.dtail) {
            if (curr?.data == data) {
                (curr.prev as ListNode<T>).next = curr.next;
                (curr.next as ListNode<T>).prev = curr.prev;
                this.size--;
                return true;
            }

            curr = (curr as ListNode<T>).next;
        }

        return false;
    }

    reverse(): void {
        type node = ListNode<T> | null;

        let first: node = this.dhead.next;
        let last: node = this.dtail.prev;

        let mid = this.size >> 1;
        for (let i: number = 0; i < mid; ++i) {
            let temp: T = (first as ListNode<T>).data as T;
            (first as ListNode<T>).data = (last as ListNode<T>).data as T;
            (last as ListNode<T>).data = temp;

            first = (first as ListNode<T>).next;
            last = (last as ListNode<T>).prev;
        }
    }

    print(): null | undefined {
        if (this.isEmpty()) {
            return null;
        }

        let curr = this.dhead.next;
        let output = '';
        let front_back = `f:${this.front()}, b:${this.back()})`;
        while (curr != this.dtail) {
            output += `${(curr as ListNode<T>).data} `;
            curr = (curr as ListNode<T>).next;
        }
        output += `(size:${this.getSize()}, ${front_back}`;
        console.log(output);
    }
}

// npm install prompt-sync
const myprompt = require("prompt-sync")({ sigint: true });

let list = new DoublyLinkedList<number>();

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
    const answer = myprompt("> ");

    switch (answer) {
        case "1": {
            let data = myprompt("push back: ");
            list.push_back(parseInt(data));
            list.print();
            break;
        }
        case "2": {
            let data = myprompt("push front: ");
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
            let data = myprompt("Insert data: ");
            let pos = myprompt("at position (1-based): ");
            list.insert(data, pos);
            list.print();
            break;
        }
        case "6": {
            let pos = myprompt("Erase a value at position (1-based): ");
            list.erase(pos);
            list.print();
            break;
        }
        case "7": {
            let data = myprompt("Remove a value: ");
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
            if (list.isEmpty()) {
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
            let pos = myprompt("Value at position (1-based): ");
            console.log(list.value_at(pos));
            break;
        }
        case "0": {
            console.log("Bye!");
            isRunning = false;
        }
    }
}