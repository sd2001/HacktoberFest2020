function clicks(val){
    document.getElementById("screen").value+=val
    
}
function clears(){
    document.getElementById("screen").value=""
}
function equalClicks(){
    var text=document.getElementById("screen").value
    var result=eval(text)
    document.getElementById("screen").value=result
}