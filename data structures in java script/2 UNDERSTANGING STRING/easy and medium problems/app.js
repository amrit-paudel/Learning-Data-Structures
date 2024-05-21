//Given an array of math equations (given as strings), return the percentage of correct answers as a string.
// Round to the nearest whole number.

function markMaths(arr) {
    const regx=/[+\/*=]/g;
    const originalArr=Array.from(arr);
    const correctArr=originalArr.flatMap((item,index)=>{ const regx=/[+-\/*=]/g;
        const [expr,ans]=item.split(/[=]/g);
        const [operator]=regx.exec(expr);
        
        const nums=expr.split(regx).map((item)=>parseInt(item));
        
        switch(operator){
            case '+':{
                if(nums[0]+nums[1]==ans){return [`${expr}=${ans}`]}
                else{return []};
                break;
            };
            case '-':{
                if(nums[0]-nums[1]==ans){return [`${expr}=${ans}`]}
                else{return []};
                break;
            }
        }

    });
    console.log(correctArr.length);
    console.log(originalArr.length)
    return `${Math.round(correctArr.length*100/originalArr.length)}%`
}
console.log(markMaths(["1+1=-1", "2+1=-2", "2+1=-2", "1-1=-2", "1-2=1", "1-1=-1", "2-2=-2", "2+2=1", "2+1=-2", "1-2=0", "2+1=-2", "2-1=1", "2+2=-1", "1-2=-1", "1-2=0", "1-2=2"]));
console.log(markMaths(["1-2=-2"]));









