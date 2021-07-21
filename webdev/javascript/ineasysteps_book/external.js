function init()
{
    document.getElementById("panel").innerHTML="Hello...from an external js file!";
    window.alert("Document Loaded!");
}
window.onload=init;