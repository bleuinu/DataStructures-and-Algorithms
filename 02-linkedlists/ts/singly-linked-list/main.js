"use strict";
exports.__esModule = true;
var ListNode = /** @class */ (function () {
    function ListNode(data, next) {
        this.data = data;
        this.next = next;
    }
    return ListNode;
}());
var SinglyLinkedList = /** @class */ (function () {
    function SinglyLinkedList() {
        this.dhead = new ListNode(null, null);
        this.size = 0;
    }
    SinglyLinkedList.prototype.getSize = function () {
        return this.size;
    };
    SinglyLinkedList.prototype.isEmpty = function () {
        return this.size == 0;
    };
    SinglyLinkedList.prototype.front = function () {
        var _a;
        if (this.isEmpty()) {
            return null;
        }
        return (_a = this.dhead.next) === null || _a === void 0 ? void 0 : _a.data;
    };
    SinglyLinkedList.prototype.back = function () {
        if (this.isEmpty()) {
            return null;
        }
        var curr = this.dhead;
        while (curr.next != null) {
            curr = curr.next;
        }
        return curr.data;
    };
    /* pos: 1-based */
    SinglyLinkedList.prototype.value_at = function (pos) {
        if (this.isEmpty()) {
            console.log("List is empty..");
            return null;
        }
        if (pos <= 0 || pos > this.size) {
            console.log("Invalid value... position:", pos);
            return null;
        }
        var curr = this.dhead;
        while (pos && curr.next) {
            curr = curr.next;
            --pos;
        }
        return curr.data;
    };
    SinglyLinkedList.prototype.push_front = function (data) {
        var newnode = new ListNode(data, this.dhead.next);
        this.dhead.next = newnode;
        this.size++;
    };
    SinglyLinkedList.prototype.push_back = function (data) {
        if (this.isEmpty()) {
            this.push_front(data);
            return null;
        }
        var curr = this.dhead;
        while (curr.next != null) {
            curr = curr.next;
        }
        var newnode = new ListNode(data, null);
        curr.next = newnode;
        this.size++;
    };
    SinglyLinkedList.prototype.pop_front = function () {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }
        var curr = this.dhead.next;
        if (this.size == 1) {
            this.dhead.next = null;
            this.size--;
            return curr === null || curr === void 0 ? void 0 : curr.data;
        }
        else {
            var temp = this.dhead.next;
            this.dhead.next = temp === null || temp === void 0 ? void 0 : temp.next;
            var data = temp === null || temp === void 0 ? void 0 : temp.data;
            temp = null;
            this.size--;
            return data;
        }
    };
    SinglyLinkedList.prototype.pop_back = function () {
        var _a, _b;
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }
        if (this.size == 1) {
            return this.pop_front();
        }
        var curr = this.dhead;
        while ((_a = curr.next) === null || _a === void 0 ? void 0 : _a.next) {
            curr = curr.next;
        }
        var data = (_b = curr.next) === null || _b === void 0 ? void 0 : _b.data;
        curr.next = null;
        this.size--;
        return data;
    };
    /* pos: 1-based */
    SinglyLinkedList.prototype.insert = function (data, pos) {
        if (pos <= 0 || pos > this.size + 1) {
            console.log("Invalid value... position:", pos);
            return null;
        }
        if (pos == 1) {
            this.push_front(data);
        }
        else if (pos == this.size + 1) {
            this.push_back(data);
        }
        else {
            var curr = this.dhead;
            --pos;
            while (pos && curr.next) {
                curr = curr.next;
                --pos;
            }
            var newnode = new ListNode(data, curr.next);
            curr.next = newnode;
            this.size++;
        }
    };
    /* pos = 1-based */
    SinglyLinkedList.prototype.erase = function (pos) {
        var _a, _b;
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
        var curr = this.dhead;
        while (pos && curr.next) {
            curr = curr.next;
            --pos;
        }
        var data = (_a = curr.next) === null || _a === void 0 ? void 0 : _a.data;
        curr.next = (_b = curr.next) === null || _b === void 0 ? void 0 : _b.next;
        this.size--;
        return data;
    };
    SinglyLinkedList.prototype.remove_value = function (data) {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return false;
        }
        var curr = this.dhead;
        while (curr.next) {
            if (curr.next.data == data) {
                var temp = curr.next;
                curr.next = curr.next.next;
                temp.next = null;
                this.size--;
                return true;
            }
            curr = curr.next;
        }
        return false;
    };
    SinglyLinkedList.prototype.reverse = function () {
        var prev = null;
        var curr = this.dhead.next;
        while (curr != null) {
            var next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        this.dhead.next = prev;
    };
    SinglyLinkedList.prototype.print = function () {
        if (this.isEmpty()) {
            return null;
        }
        var curr = this.dhead.next;
        var output = '';
        var front_back = "f:".concat(this.front(), ", b:").concat(this.back(), ")");
        while (curr) {
            output += "".concat(curr.data, " ");
            curr = curr.next;
        }
        output += "(size:".concat(this.getSize(), ", ").concat(front_back);
        console.log(output);
    };
    return SinglyLinkedList;
}());
var prompt = require("prompt-sync")({ sigint: true });
var list = new SinglyLinkedList();
console.log("------- Operations ------");
console.log(" 1. push_back      2. push_front");
console.log(" 3. pop_back       4. pop_front");
console.log(" 5. insert");
console.log(" 6. erase          7. remove_value");
console.log(" 8. front          9. back");
console.log("10. size          11. isEmpty");
console.log("12. print         13. reverse");
console.log("14. valueAt        0. Exit");
var isRunning = true;
while (isRunning) {
    var answer = prompt("> ");
    switch (answer) {
        case "1": {
            var data = prompt("push back: ");
            list.push_back(parseInt(data));
            list.print();
            break;
        }
        case "2": {
            var data = prompt("push front: ");
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
            var data = prompt("Insert data: ");
            var pos = prompt("at position (1-based): ");
            list.insert(data, pos);
            list.print();
            break;
        }
        case "6": {
            var pos = prompt("Erase a value at position (1-based): ");
            list.erase(pos);
            list.print();
            break;
        }
        case "7": {
            var data = prompt("Remove a value: ");
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
            }
            else {
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
            var pos = prompt("Value at position (1-based): ");
            console.log(list.value_at(pos));
            break;
        }
        case "0": {
            console.log("Bye!");
            isRunning = false;
        }
    }
}