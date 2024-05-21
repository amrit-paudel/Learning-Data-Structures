// practice
const intro='my name is Amrit poudel';
const introArr=intro.split(" ");
console.log(introArr);
const newIntroArr=introArr.filter(item=>item.length>3); // testo item matraa jayos jasko length 3 vanda thulo hos
console.log(newIntroArr)

//********************* */
const arr=[10,20,3,40];
const isPrime=(item)=>{let rem;
for(i=2;i<=item;i++){
rem=item%i;if(rem==0){break}
}
if(i==item){return true}
}
console.log(arr.every(isPrime));  // isPrime method goes to each and every item and checks whether every item are prime or not 
// this method strictly demands every item to satisfy the condition 
console.log(arr.some(isPrime));// this also goes to every item and checks whether some item ( at least one item ) satisfy the given condition or not.

var num=[10,20,30,40,50,11];
var strArr=['amrit','ashish','anish','ramesh'];
var objArr=[
    {name:'amrit',addr:'ratnanagar-10'},
    {name:'anish',addr:'bharatpur-12'},
    {name:'ramesh',addr:'nippani-20'},
]

function isStrangePair(str1, str2) {
	return str1[0]==str2.split("").pop()&&str1.split("").pop()==str2[0];
}
console.log(isStrangePair("ratio", "orator"))

// use of reduce method
function transform(arr) {
    const resultArr=arr.reduce((accu,curr)=>{
       if(curr%2==0){return accu.concat(curr-1)}
       else if(curr%2!==0){return accu.concat(curr+1)}
   },[]);return resultArr;
}
console.log(transform([1, 2, 3, 4, 5]));