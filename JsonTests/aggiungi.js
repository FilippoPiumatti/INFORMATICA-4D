"use strict"

let jsonDoc;

window.onload=function(){
    let json = localStorage.getItem("test");
    if(json!=null)
        jsonDoc = JSON.parse(json);
    else
        jsonDoc = [];
    
    let cmb = document.createElement("select");

    let opt = document.createElement("option");
    opt.text = "windows.jpeg";
    cmb.appendChild(opt)

    opt = document.createElement("option");
    opt.text = "linux.jpeg";
    cmb.appendChild(opt)


    opt = document.createElement("option");
    opt.text = "macosx.jpeg";
    cmb.appendChild(opt)

    cmb.setAttribute("id", "cmbSO")

    this.document.getElementById("divCmb").style.paddingBottom = "20px"

    document.getElementById("divCmb").appendChild(cmb);
}

function salva(){
    let test = {};
    test.TestId = document.getElementById("txtTestId").value;
    test.TestType = document.getElementById("txtTestType").value;
    test.Name = document.getElementById("txtName").value;
    test.CommandLine = document.getElementById("txtCommandLine").value;
    test.Input = document.getElementById("txtInput").value;
    test.Output = document.getElementById("txtOutput").value;
    test.DataExecution = document.getElementById("txtDataExecution").value;
    test.OperatingSystem = document.getElementById("cmbSO").value;
    jsonDoc[jsonDoc.length] = test;
    let jsonS = JSON.stringify(jsonDoc);
    localStorage.setItem("test", jsonS);
    ritorna();
}

function ritorna(){
    window.location.href = "index.html";
}