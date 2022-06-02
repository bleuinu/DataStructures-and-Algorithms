var ListNode = /** @class */ (function () {
    function ListNode(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
    return ListNode;
}());
var DoublyLinkedList = /** @class */ (function () {
    function DoublyLinkedList() {
        this.dhead = new ListNode(null);
        this.dtail = new ListNode(null);
        this.dhead.next = this.dtail;
        this.dtail.prev = this.dhead;
        this.size = 0;
    }
    DoublyLinkedList.prototype.getSize = function () {
        return this.size;
    };
    DoublyLinkedList.prototype.isEmpty = function () {
        return this.size == 0;
    };
    DoublyLinkedList.prototype.front = function () {
        var _a;
        if (this.isEmpty()) {
            return null;
        }
        return (_a = this.dhead.next) === null || _a === void 0 ? void 0 : _a.data;
    };
    DoublyLinkedList.prototype.back = function () {
        var _a;
        if (this.isEmpty()) {
            return null;
        }
        return (_a = this.dtail.prev) === null || _a === void 0 ? void 0 : _a.data;
    };
    /* pos: 1-based */
    DoublyLinkedList.prototype.value_at = function (pos) {
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
    DoublyLinkedList.prototype.push_front = function (data) {
        var newnode = new ListNode(data);
        this.dhead.next.prev = newnode;
        newnode.prev = this.dhead;
        newnode.next = this.dhead.next;
        this.dhead.next = newnode;
        this.size++;
    };
    DoublyLinkedList.prototype.push_back = function (data) {
        var newnode = new ListNode(data);
        this.dtail.prev.next = newnode;
        newnode.prev = this.dtail.prev;
        newnode.next = this.dtail;
        this.dtail.prev = newnode;
        this.size++;
    };
    DoublyLinkedList.prototype.pop_front = function () {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }
        var temp = this.dhead.next;
        temp.prev.next = temp.next;
        temp.next.prev = temp.prev;
        this.size--;
        return temp.data;
    };
    DoublyLinkedList.prototype.pop_back = function () {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return null;
        }
        var curr = this.dtail.prev;
        this.dtail.prev = curr.prev;
        curr.prev.next = this.dtail;
        this.size--;
        return curr.data;
    };
    /* pos: 1-based */
    DoublyLinkedList.prototype.insert = function (data, pos) {
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
            while (pos && curr.next) {
                curr = curr.next;
                --pos;
            }
            var newnode = new ListNode(data);
            newnode.prev = curr.prev;
            newnode.next = curr;
            curr.prev.next = newnode;
            curr.prev = newnode;
            this.size++;
        }
    };
    /* pos = 1-based */
    DoublyLinkedList.prototype.erase = function (pos) {
        if (pos <= 0 || pos > this.size) {
            console.log("Invalid value... position:", pos);
            return null;
        }
        var curr = this.dhead;
        while (pos && curr.next) {
            curr = curr.next;
            --pos;
        }
        var data = curr.data;
        curr.prev.next = curr.next;
        curr.next.prev = curr.prev;
        this.size--;
        return data;
    };
    DoublyLinkedList.prototype.remove_value = function (data) {
        if (this.isEmpty()) {
            console.log("List is empty...");
            return false;
        }
        var curr = this.dhead.next;
        while (curr != this.dtail) {
            if ((curr === null || curr === void 0 ? void 0 : curr.data) == data) {
                curr.prev.next = curr.next;
                curr.next.prev = curr.prev;
                this.size--;
                return true;
            }
            curr = curr.next;
        }
        return false;
    };
    DoublyLinkedList.prototype.reverse = function () {
        var first = this.dhead.next;
        var last = this.dtail.prev;
        var mid = this.size >> 1;
        for (var i = 0; i < mid; ++i) {
            var temp = first.data;
            first.data = last.data;
            last.data = temp;
            first = first.next;
            last = last.prev;
        }
    };
    DoublyLinkedList.prototype.print = function () {
        if (this.isEmpty()) {
            return null;
        }
        var curr = this.dhead.next;
        var output = '';
        var front_back = "f:".concat(this.front(), ", b:").concat(this.back(), ")");
        while (curr != this.dtail) {
            output += "".concat(curr.data, " ");
            curr = curr.next;
        }
        output += "(size:".concat(this.getSize(), ", ").concat(front_back);
        console.log(output);
    };
    return DoublyLinkedList;
}());
// npm install prompt-sync
var myprompt = require("prompt-sync")({ sigint: true });
var list = new DoublyLinkedList();
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
    var answer = myprompt("> ");
    switch (answer) {
        case "1": {
            var data = myprompt("push back: ");
            list.push_back(parseInt(data));
            list.print();
            break;
        }
        case "2": {
            var data = myprompt("push front: ");
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
            var data = myprompt("Insert data: ");
            var pos = myprompt("at position (1-based): ");
            list.insert(data, pos);
            list.print();
            break;
        }
        case "6": {
            var pos = myprompt("Erase a value at position (1-based): ");
            list.erase(pos);
            list.print();
            break;
        }
        case "7": {
            var data = myprompt("Remove a value: ");
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
            var pos = myprompt("Value at position (1-based): ");
            console.log(list.value_at(pos));
            break;
        }
        case "0": {
            console.log("Bye!");
            isRunning = false;
        }
    }
}
