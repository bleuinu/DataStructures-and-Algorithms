## Arrays 

---

Array is a collection of similar data stored in a contiguous memory location and can be accessed randomy using indices of an array. 

```cpp
int a1 = 1;
int a2 = 2;
int a3 = 3;
int a4 = 4;
int a5 = 5;

/* An array of size 5 */
int a[5] = {1, 2, 3, 4, 5};

printf("%d\n", a[0]) // 1
printf("%d\n", a[1]) // 2
printf("%d\n", a[2]) // 3
printf("%d\n", a[3]) // 4
printf("%d\n", a[4]) // 5
```

The index of an array starts from `0` and goes up to the `size of array - 1`.

--- 

- Advantages of using arrays:
  - Arrays allow random access to elements - constant time access
  - Arrays have better [cache locality](https://en.wikipedia.org/wiki/Locality_of_reference)
  - We can use a single variable to represent many data.
- Disadvantages of using arrays:
  - Fixed size - cannot shrink nor expand the size during run-time because of static memory allocation.
  - Insertion and deletion can be costly due to shifting of elements in an array.