// printing all two digits twisted primes 
// thoses promes which are primes even after reversing them are twisted primes


// function to check primes
// returns true if number is prime else returns false
function isPrime(num) {
    for (let i = 2; i <= Math.floor(Math.sqrt(num)); i++) {
        let rem;
        rem = num % i;
        if (rem == 0) { return false }
    }
    return true;
}


// function to reverse the number
function reverse(num) {
    var reverseNum = 0;
    do {


        let rem ;
        rem = num % 10;
        num /= 10;
        num=Math.floor(num);
        reverseNum = reverseNum * 10 + rem;
        
    } while (num!=0)
    return reverseNum;
}


// function to check and print twisted primes

function twistedPrimes(n){
    const twistedPrimesArray=[];
    for(let i=1;i<=n;i++){
        if(isPrime(i)){
            const revNum=reverse(i);
            if(isPrime(revNum)){
                twistedPrimesArray.push(i);
            }
        }
    }
    return twistedPrimesArray.join(" ");
}

console.log(twistedPrimes(1000000000000))
