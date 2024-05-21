// recursion problems
// all we need is 
//  1) A base case
//  2) A recursive case

// 1) Sum of first n numbers 

function sum(n) {
    if (n == 1) { return n }
    else {
        return n + sum(n - 1);
    }
}

console.log(sum(4));


//  2) power function to find out the power when provides the base and exponent

function power(base, exponent) {
    if (exponent == 0) { return 1 }
    else {
        return base * power(base, exponent - 1);
    }
}
console.log(power(2, 3));


//  3) to calculate the factorial of any number
function fact(num) {
    if (num == 0) { return 1 }
    else {
        return num * fact(num - 1);
    }
}
console.log(fact(3));

//  4) function returns the product of all the numbers of an array 
function productOfArray(arr) {
    if (arr.length == 0) { return 1 }
    else {
        return arr.shift() * productOfArray(arr);
    }
}
console.log(productOfArray([4, 3, 2, 1]));


//  5) Function to search some data inside the object 
var nestedObject = {
    data: {
        info: {
            stuff: {
                thing: {
                    moreStuff: {
                        magicNumber: 44,
                        something: 'foo2'
                    }
                }
            }
        }
    }
};
function contains(obj, value) {
    for (key in obj) {
        if (obj[key] == value) { return true }
        else {
            return contains(obj[key], value);
        }
    }
}
console.log(contains(nestedObject, 44));


//  6) Given a multi-dimensional integer array, return the total number of integers stored inside this array

const integers = totalIntegers([[[5], 3], 0, 2, ['foo'], [], [4, [5, 6]]]);
var count=0;
function totalIntegers(arr){
    if(arr.length==0){return 0}      // base case 
    let count=0;
    let firstItem=arr.shift();
    if(Number.isInteger(firstItem)){count++}
    else if(Array.isArray(firstItem)){count+=totalIntegers(firstItem)}
    return count+=totalIntegers(arr);

}
console.log(integers);


//  7) a function that sums squares of numbers in list that may contain more lists

function squareSum(arr){
    let square=0;
    if(arr.length==0){return 0}
    for(item of arr){
        if(Number.isInteger(item)){square+=item*item}
        else if(Array.isArray(item)){square+=squareSum(item)}
        if(arr[arr.length-1]==item){return square}
    }
}

console.log(squareSum([1,2,3]))