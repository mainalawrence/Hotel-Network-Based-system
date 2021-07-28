.pragma library

function stringtoInt(s) {
    return parseInt(s);
}

function stringtoDouble(s){
    return parseFloat(s);
}

function ifempty(s){
   if(s==="") return false;
   else return true;
}

let Datab=[];
function orderDetails(name,cost,amount,total){
    let Data={
        name:name,
        cost:cost,
        amount:amount,
        total:total,
    }
  Datab.push(Data)
}

function added(position,name,cost,amount,total)
{
console.log(JSON.stringify(Datab[position]) )
    Datab[position]={
        name:name,
        cost:cost,
        amount:amount+1,
        total:cost*(amount+1)
    }
 console.log(JSON.stringify(Datab[position]) )

}
function subtructed(position,name,cost,amount,total)
{
    console.log(JSON.stringify(Datab[position]) )
        Datab[position]={
            name:name,
            cost:cost,
            amount:amount<1?amount:amount-1,
            total:cost*(amount<1?amount:amount-1)
        }
     console.log(JSON.stringify(Datab[position]) )
}

let orderdata=[];
const func=(data) =>{
 console.log(data)
    orderdata.push((data));
    console.log(orderdata)
}
