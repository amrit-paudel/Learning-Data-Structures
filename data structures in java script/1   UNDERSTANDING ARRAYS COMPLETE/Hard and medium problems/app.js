//Create a function that can convert from normal notation to tally-mark notation and vice versa. In tally-mark notation, a number can be decomposed as the sum of 5s + remainder.
//The function will look like this: switchNotation([current scores], desired notation)
// use of many concepts 

const switchNotation=(scores,desired_notation)=>{
    const udmath={
        add:function(item){const itm=item.toString();
            let result=0;
            for(temp of [...itm]){result+=parseInt(temp)};return result;
        }
    }
    switch(desired_notation){
        case 'normal':{
            return scores.map((item)=>udmath.add(item));
            break;
        }
        case 'tally':{
            return scores.map((item)=>{return item%5!==0?parseInt('5'.repeat(Math.floor(item/5))+item%5):parseInt('5'.repeat(Math.floor(item/5)))}    /*'5'.repeat(Math.floor(item/5))+item%5*/);
            break;
        }
    }
}
console.log(switchNotation([15, 29, 5, 3], "tally"));



numbers=[10,20,30,40,40,50];
console.log(numbers.every((item,index)=>numbers.indexOf(item)==index));

console.log(numbers.filter((item,index)=>numbers.indexOf(item)!==index))



//Create a function takes in two arrays and returns an intersection array and a union array

const intersectionUnion=(arr1,arr2)=>{
    const totalArr=arr1.concat(arr2);
    function filterTheArray(array,str){
       if(str=='intersection') return array.filter((item,index)=>array.indexOf(item)==index)
       else if(str=='union') return array.filter((item,index)=>array.indexOf(item)!==index)
    }
    let union=filterTheArray(totalArr,'union');
    let intersec=filterTheArray(totalArr,'intersection');
    if(!union.every((item,index)=>union.indexOf(item)==index)){union=filterTheArray(union,'intersection')}
    
    if(!intersec.every((item,index)=>intersec.indexOf(item)==index)){intersec=filterTheArray(intersec,'intersection')}

    return [union.sort(),intersec.sort()]; 
}
console.log(intersectionUnion([1, 2, 3, 4, 4], [4, 5, 9]));





