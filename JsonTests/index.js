"use strict"
let jsonDoc;
let pos;

window.onload = function(){
    let json = localStorage.getItem("test");
    if(json!=null){
        jsonDoc = JSON.parse(json);
        console.log(jsonDoc);
        visualizza(); //visualizzazione della tabella
        console.log(jsonDoc)
    }
}

function visualizza(){
    let tBody = document.getElementById("tabTest");
    tBody.innerHTML = "";

    for(let i=0; i<jsonDoc.length; i++){
        let test = jsonDoc[i];
        let tr = document.createElement("tr");
        tBody.appendChild(tr);
        //Scorriamo le chiavi e otteniamo ogni singolo valore
        for(let key in test){
            if (key=="OperatingSystem") {
                let td = document.createElement("td");
                let img = document.createElement("img");
                if (test[key]== "windows.jpeg") {
                    img.src = "img/windows.jpeg";
                }else if (test[key] == "linux.jpeg") {
                    img.src = "img/linux.jpeg";
                }else{
                    img.src  = "img/macosx.jpeg";
                }
                img.style.width = "30px";
                img.style.height = "30px";
                td.appendChild(img);
                tr.appendChild(td);
            }
            let td = document.createElement("td");
            td.innerText = test[key];
            tr.appendChild(td);
        }
        let td = document.createElement("td");
        let btn = document.createElement("input");
        btn.type= "button";
        btn.value = "ELIMINA";
        btn.setAttribute("id", i);
        btn.addEventListener("click", function(){
           elimina(this.getAttribute("id"));
        });
        td.appendChild(btn);
        tr.appendChild(td);
    }
}

function aggiungi(){
    window.location.href = "aggiungi.html";
}

function leggiRecord(){
    let div = document.getElementById("contenuto");
    div.innerHTML = "";
    for(let key in jsonDoc[pos])
    {
        div.innerHTML += key + " : " + jsonDoc[pos][key] + "<br>";
    }
}

function primo(){
    pos = 0;
    leggiRecord();
}

function ultimo(){
    pos =jsonDoc.length-1;
    leggiRecord();
}

function avanti(){
    if(pos<(jsonDoc.length-1)){
        pos++;
        leggiRecord();
    }
    else
        alert("you already on the last Test!");
}

function indietro(){
    if(pos>0){
        pos--;
        leggiRecord()
    }
    else
        alert("you aldready on the first test");
}

function elimina(id){
    jsonDoc.splice(id,1);
    let jsonS = JSON.stringify(jsonDoc);
    localStorage.setItem("test",jsonS);
    visualizza();
}
function visualizzaJSON(){
    let jsonS = JSON.stringify(jsonDoc);
    let div = document.createElement("div");

    div.style.border = "5px";
    div.style.borderRadius = "6px";
    div.style.borderColor  = "black";
    div.style.height  = "150px";
    div.style.margin = "0px auto";
    div.style.paddingTop = "20px"
    div.style.fontFamily = "verdana"
    div.innerHTML = jsonS;
   let body = document.getElementById("b");
   body.appendChild(div);
}