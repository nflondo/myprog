function init()
{
    var yes = true, no = false;
    var blnA = yes && yes;
    var blnB = yes && no;
    var blnC = no || yes;
    var blnD = no || no;
    var tog = !yes; //reverse the value

    var str="Are both true?" + blnA;
    str+="<br>Are both true now? "+ blnB;
    str+="<br>Is either value true? "+ blnC;
    str+="<br>Is either value true now?"+ blnD;
    str+="<br>Initial value "+ yes;
    str+="<br>Toggled value "+ tog;    

    document.getElementById("panel").innerHTML=str;
}

window.onload=init;

