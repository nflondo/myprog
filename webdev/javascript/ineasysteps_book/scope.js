
var global="This is worldwide Global news<hr>";

function us(obj)
{
    var local="**This is the United States Local News**<br>";
    obj.innerHTML+=local;
    obj.innerHTML+=global;
}
function eu(obj)
{
    var local="--This is the European Local News--<br>";
    obj.innerHTML+=local;
    obj.innerHTML+=global;
}

function init()
{
    var obj=document.getElementById("panel");
    obj.innerHTML=global;
    us(obj);
    eu(obj);
}

window.onload=init;