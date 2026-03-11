let stackA=[]
let stackB=[]

function pushWord(){

let word=document.getElementById("word").value

if(word==="") return

stackA.push(word)

document.getElementById("word").value=""

render()

}

function undo(){

if(stackA.length>0){

let item=stackA.pop()
stackB.push(item)

}

render()

}

function redo(){

if(stackB.length>0){

let item=stackB.pop()
stackA.push(item)

}

render()

}

function clearStacks(){

stackA=[]
stackB=[]

render()

}

function render(){

let A=document.getElementById("stackA")
let B=document.getElementById("stackB")

A.innerHTML=""
B.innerHTML=""

stackA.forEach(item=>{

let div=document.createElement("div")
div.className="block"
div.innerText=item
A.appendChild(div)

})

stackB.forEach(item=>{

let div=document.createElement("div")
div.className="block"
div.innerText=item
B.appendChild(div)

})

}
