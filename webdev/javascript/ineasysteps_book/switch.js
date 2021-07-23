function init()
{
    //var panel=document.getElementById("panel");
    var day;

    switch ( 5 - 2)
    {
        case 1 : day="Monday";          break;
        case 2 : day="Tuesday";         break;
        case 3 : day="Wednesday";       break;
        case 4 : day="Thursday";        break;        
    }

    //panel.innerHTML="It's " + day;
    document.getElementById("panel").innerHTML="It's "+day;
}

window.onload=init;

