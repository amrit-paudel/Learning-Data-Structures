// here we filter the array and get an array of having non repeating items
const numbers=[10,20,30,40,50,60,70,40,30,10];
const nums=numbers.filter((item,index)=>numbers.indexOf(item)==index);
console.log(nums);

//Create a function that takes an array of numbers and returns only the even values.
const noOdds=(arr)=>{
    return arr.filter((item)=>item%2==0)
}
console.log(noOdds([1, 2, 3, 4, 5, 6, 7, 8]))



//Create a function that takes an array of strings and returns an array with only the strings 
//that have numbers in them. If there are no strings containing numbers, return an empty array
// pretty hard problem 
function numInStr(arr) {
   /* return arr.flatMap((item)=>{
        const charArr=item.split("");
        if(charArr.some((item)=>parseInt(item))){return [item]}
        else{return []}
    })*/
   // we were able to solve this by two method see below for regx method
    const regx=/([a-zA-Z]+\d+)|(\d+[a-zA-Z]+)/;
    return arr.flatMap((item)=>(regx.test(item))?[item]:[])
}
console.log(numInStr(["1a", "a", "2b", "b"]));




//Create a function that identifies the very first item that has recurred in the string argument passed. 
//It returns the identified item with the index where it first appeared and the very next index 
//where it resurfaced -- entirely as an object; or as an empty object if the passed argument is either null,
 //undefined, empty string, or no recurring item exists.
 const recurIndex=(str)=>{

    const findRepeatingChar=(str)=>{
        const strArr=str.split("").sort();
        for(i=0;i<=strArr.length-1;i++){
            if(strArr[i]===strArr[i+1]){return strArr[i]}
        }
    }

     let repeatingChar=findRepeatingChar(str);console.log(repeatingChar)
     const key=`${repeatingChar}`
     return {key:[str.split("").indexOf(repeatingChar),str.split("").reverse().indexOf(repeatingChar)+str.length-1]}
 }
 console.log(recurIndex("AREDCBSDERD"))






