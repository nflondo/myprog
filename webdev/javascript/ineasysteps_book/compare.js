function init()
{
    var strA = "JavaScript" === "JAVASCRIPT";
    var strB = "JavaScript" === "JavaScript";
    var flt = 7.5 === 7.5;
    var intA = 8 !== 8;
    var intB = 24 > 12;
    var intC = 24 < 12;
    var intD = 24 <= 24;

    var str="String equality test 1: " + strA;
    str+="<br>String equality test 2: "+ strB;
    str+="<br>Float equality test 2: "+ flt;
    str+="<br>Integer equality test 2: "+ intA;
    str+="<br>Greater equality test 2: "+ intB;
    str+="<br>Less equality test 2: "+ intC;
    str+="<br>Less than or equal: "+ intD;

    document.getElementById("panel").innerHTML=str;
}

window.onload=init;

