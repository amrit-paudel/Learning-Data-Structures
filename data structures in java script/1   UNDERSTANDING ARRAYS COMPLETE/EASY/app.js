//Create a function that changes specific words into emoticons. Given a sentence as a string, replace the words smile, grin, sad and mad with their corresponding emoticons

const emotify = (str) => {
    const wordEmoticon = {
        smile: ':D',
        grin: ':)',
        sad: ':(',
        mad: ':P',
    };
    const strArr = str.split(" ");
    const key = strArr.pop();
    strArr.push(wordEmoticon[key]);
    return strArr.join(" ");
};
console.log(emotify("Make me smile"))



// checking whether the object contains the particular key or not 
function containsKey(obj, key) {
    return key in obj;
}
console.log(containsKey({ a: 10, b: 20, c: 30, d: 40 }, 'd'))



// Create a function that takes an array and finds the integer which appears an odd number of times.
function findOdd(arr) {
    for (i = 0; i <= arr.length - 1; i++) {
        let count = 0;
        for (temp of arr) {
            if (arr[i] == temp) { ++count }
        }
        if (count % 2 !== 0) { return arr[i] }
    }
}
console.log(findOdd([20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5]));



//Write a function that returns true if all characters in a string are identical and false otherwise.
const isIdentical=(str)=>{
 return str==str.split("").reverse().join("")?true:false
}


// Create a function that takes two parameters (start, stop), and returns the sum of all even numbers in the range.
// Here I have used .reduce() method so a nice way of doing 
const sumEvenNumsInRange=(start,end)=>{
    const evenNum=[];
    for(i=start;i<=end;i++){
        if(i%2==0){evenNum.push(i)}
    }
    return evenNum.reduce((accu,current)=>{return accu+current},0)
}
console.log(sumEvenNumsInRange(1,10))

//Create a function that replaces all the vowels in a string with a specified character.
const replaceVowels=(str,char)=>{
    const regx=/[a,e,i,o,u]/g;
    return str.replace(regx,char)
};
console.log(replaceVowels("minnie mouse", "?"))


//Write a function that takes an integer and returns a string with the given number of "a"s in Edabit.
const howManyTimes=(num)=>{
    if(num==0){return 'Edabit'}else{
        const temp='Edabit'.split("");
        for(i=0;i<=num-2;i++){
            temp.splice(temp.indexOf('a'),0,'a');
        }
        return temp.join("");
    }
}
console.log(howManyTimes(3))



























