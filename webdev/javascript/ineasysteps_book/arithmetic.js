function init()
{
    var sum=80 + 20;
    var sub=sum -50;
    var mul=sum * 5;
    var div=sum /4;
    var mod = sum % 2;
    var inc = ++sum;
    var dec = --sum;

    var str= "Sum:"+sum+"<br>Substraction:"+sub;
    str+="<br>Multiplication:"+mul+"<br>Division:"+div;
    str+="<br>Modulus:"+mod;
    str+="<br>Increment:"+inc+"<br>Decrement:"+dec;
    //write string into the panel element
    document.getElementById("panel").innerHTML=str;
}

window.onload=init;