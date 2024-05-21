

//  function returns last character of either string or array passed to it 
function lastItem(input) {
	if(input.length==0){return undefined}
	else if(Array.isArray(input)){return input.pop()}
	else{
		return input.split("").pop();
	}
}
console.log(lastItem('hi i am amrit poudel'));



// function counts the total number of characters to form the given shape
const countCharacters=(arr)=>{
	if(arr.length==0){return 0};
	return arr.pop().split("").length+countCharacters(arr)
}

console.log(countCharacters(['$$%%%','@']))



// finding largest number in an array

const findLargestNum=(arr)=>{
if(arr.length==0){return 'enter a non empty array'}
let max=arr[0];
for(i=0;i<=arr.length-1;i++){
	if(arr[i]>max){max=arr[i]}
	if(i==arr.length-1){return max}
}
}


// function to test whether the word lies between the first and second word or not as per dictionery order


const isBetween=(first,last,word)=>{
	//return word>first && word<last

	return [first,last,word].sort()[1]==word;
}

console.log(isBetween("apple", "banana", "azure"));


// function returns the name of month when provided the number of the month

const monthName=(num)=>{
	const month=['January','febuary','march','april','may','june','july','august','september','october','november','december'];
	return month[num-1];
}

console.log(monthName(12))



// function returns true if sam and frodo are close to each other in the provided array
function middleEarth(arr){
	return arr[arr.indexOf('Sam')+1]=='Frodo'||arr[arr.indexOf('Frodo')+1]=='Sam'
}

console.log(middleEarth(["Frodo", "Sam", "Gandalf"]))


// creating an object that gives us the fullname and email address
class Employee{
constructor(first,last){
	this.firstName=first;
	this.lastName=last;
	this.fullname=`${this.firstName} ${this.lastName}`
	this.email=`${[...arguments].join(".")}@company.com`.toLowerCase();
}
};
const emp1 = new Employee("John", "smith");
console.log(emp1.fullname)
console.log(emp1.email)



// function takes array of numbers and returns the smallest number in the array 
const findSmallestNum=(arr)=>{
	let smallNum=arr[0];
	for(let i=0;i<=arr.length-1;i++){
		if(arr[i]<smallNum){smallNum=arr[i]}
	}
	return smallNum;
}

console.log(findSmallestNum([10,20,5,3,-1]));


// function to multiply all the values of an array with the length and return the new array 

const multiplyByLength=(arr)=>{
	const newarr=[];
	for(temp of arr){
		temp*=arr.length;
        newarr.push(temp)
	}
return newarr
}
console.log(multiplyByLength([2,3,4,5]))



// function that takes numbers from 1 to 60  and construct the -------  hyphen strings of the corresponding numbers 
const Go=(num)=>{
	if(num > 60||num<1){return 'Enter a number in between 1 and 60'};
	let hyphenArr=[];
	for(i=1;i<=num;i++){
		hyphenArr.push("-");
	}
	return hyphenArr.join("");
}
console.log(Go(60))



// function returns the new arraw of first and last element of passed array 
function firstLast(arr) {
	return [arr[0],arr.pop()]
}
console.log(firstLast([10,20,30]))




//Creating a function that adds a string ending to each member in an array.
const addEnding=(arr,str)=>{
	const newArr=[];
	for(temp of arr){
		newArr.push(`${temp}${str}`)
	}
return newArr;
}
console.log(addEnding(["new", "pander", "scoop"], "er"));


// Write a function that classifies the missing angle as either "acute", "right", or "obtuse" based on its degrees.

const missingAngle=(angle1,angle2)=>{
	const diff=180-angle1-angle2;
	return (diff==90?'right':(diff<90)?'acute':'obtuse')
}
console.log(missingAngle(27, 59));


//Given a number, return an array containing the two halves of the number. If the number is odd, make the rightmost number higher.

const numberSplit=(num)=>{
	return (num%2==0?[num/2,num/2]:[Math.floor(num/2),Math.floor(num/2)+1])
}
console.log(numberSplit(2))


// calculating the determinant of the provided 2*2 matrix 
const calcDeterminant=(arr)=>{

	arr=[...arr];
	return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
}
console.log(calcDeterminant([
	[1, 2],
	[3, 4]
  ]))


  // Given an array of numbers, negate all elements contained within

  const negate=(arr)=>{
	 return  arr.length==0?[]:negateArr(arr);
	 function negateArr(arr){
		 const negArr=[];
		 for(temp of arr){
			 negArr.push(-temp)
		 }
		 return negArr;
	 }
  }
  console.log(negate([1, 2, 3, 4]))



  //Create a function that takes an initial word and extracts any words that start with the same letters as the initial word.
  // a nice, beautiful and efficient and short code
  const dictionary=(initialWord,arr)=>{
	  const words=[];
	  for(temp of arr){
		  if(initialWord==temp.slice(0,initialWord.length)){ words.push(temp)}
	  }
	  return words;
  }
  console.log(dictionary("tri", ["triplet", "tries", "trip", "piano", "tree"]));


  //Create a function that reverses a boolean value and returns the string "boolean expected" if another variable type is given.
 // shorth efficient and nice code 
  const reverse=(value)=>{
	return typeof(value)=='boolean'?value==true?false:true:'boolean expected'
}
console.log(reverse(false))



//function returns the difference between the largest and smallest numbers in the array 
function difference(nums) {
	return Math.max(...nums)-Math.min(...nums);
}
console.log(difference([10,20,30,40,50]))



// this one is super useful analyze this 
const str='amrit poudel';
function removeVowels(str) {
		 return str.replace(/[aeiou]/g, '')
		
   }
   console.log(removeVowels(str))






//Create a function to remove all null values from an array.
// beautiful  and  nice code 
function removeNull(arr) {

//	return arr.filter(Boolean);
	// or
	 return arr.filter(item=>item!==null)

	 //return arr.map((item)=>{if(item!==null){return item}}) it won't work since in .map() method it iterated over each and every element


   // or

/*return arr.filter((item)=>{
	return item!==null;
})*/

}
console.log(removeNull([7, 8, null, 9]))





// Create a function that takes two strings and returns true if the first string ends with the second string; otherwise return false.
// nice and beautiful code 
function checkEnding(str1, str2) {
	return str1.split("").reverse().join("").slice(0,str2.length)==str2.split("").reverse().join("");
}
console.log(checkEnding("feminine", "nine"));





// nice useof regX
// nice beautiful code 

function sameCase(str) {
	const regx1=/^[A-Z]+$/g;
	const regx2=/^[a-z]+$/g;
	return regx1.test(str)||regx2.test(str);
  
}const amr='amRIt';
console.log(sameCase(amr));


const nameee={
	name1:'amrit',
	name2:'poudel',
	name3:'ashish'
}



















