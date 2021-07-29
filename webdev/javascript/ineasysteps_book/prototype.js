
function Car( make, model, color)
{
    //properties
    this.make=make;
    this.model=model;
    this.color=color;

}

function init()
{
    var panel=document.getElementById("panel");
    var myCar= new Car(" Ford", " Focus", " blue");

    //extend the object by adding another property and assigning it a value
    Car.prototype.doors=4;
    //Loop to write the name and value of each object property in the panel, and a final ruled line
    for( property in myCar )
    {
        if( myCar[property] !== "")
        {
            panel.innerHTML+=( property+": "+myCar[property]+"<br>");
        }
    }
    panel.innerHTML+="<hr>";

    myCar.make="Dodge";
    myCar.model="Challenger";
    myCar.color="Orange";
    myCar.doors=2;

    for( property in myCar )
    {
        if( myCar[property] !== "")
        {
            panel.innerHTML+=( property+": "+myCar[property]+"<br>");
        }
    }
    panel.innerHTML+="<hr>";
}
window.onload=init;

