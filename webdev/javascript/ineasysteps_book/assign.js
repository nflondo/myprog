function init()
{
    var msg="JavaScript";msg+=" Code";
    var flt=7.5;flt +=2.25;
    var intA=8; intA -=4;

    var str = "Add & assign string:"+msg;
    str+="<br>Add & assign float: "+flt;
    str+="<br>Substract & assign: "+intA;

    document.getElementById("panel").innerHTML=str;
}

window.onload=init;