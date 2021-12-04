"use strict"
let _selector; //posso prenderee qualsiasi cosa per che punta la conterintree
$(document).ready(function(){
    _selector = $("fieldset"); //accedo a tutti i tag fieldset
    console.log(_selector.length);// stampo la  quantita di fieldset presenti
    _selector = _selector.eq(0);// prende l ennesimo elemento di una lista
    _selector.find("button").eq(0).on("click",colore) //  va a cercare nel contenitore a cui punta tutti i tag button
    //se ci fossero stati altri button , av rei usato l eq come prima

})

function colore(){
    console.log("Cambio colore al body");
    $("body").css("backgroundColor","red");
}

function visualizza(codice){
    let messGenerico = "";
    switch (codice) {
        case 1:
            //.val() prende il valore dei campiu di input, tipo value
            messGenerico = _selector.find("input[type = text]").first().val();//trovami dentro fieldset, tutti i tag input type text
            break;
        case 2:
            //messGenerico = _selector.find("select").eq(0).val(); // N.B. value prende solo il value, non il testo, se non ce il value, prende il testo
            //messGenerico = $("select:first-child").val();//mi prendo la prima select se ne ho piu di una
            //messGenerico  = $("select:first-of-type").val(); // prende il primo del tipo select
            messGenerico = $("select").eq(0).val();//prendo il primo con la funzioen jquery .eq();
            break;
        case 3:
            /*la funzione .each() fa si che per ognuna delle checkbox vengano eseguite le seguenti procedure*/ 
            _selector.children("fieldset").first().find(":checkbox").each( // la checkbox necessita di : prima
                function(index,elem){
                    messGenerico += $(elem).val() + " - indice del checkbox: " + index + "\n";
                }
            );
            break;
        case 4:
            //la funzione .filter() cercva tuti i figli di fieldset

            _selector.children().filter("fieldset").eq(0).children()
            .children(":checkbox:checked").each(function(index,elem){
                messGenerico += $(elem).val() + " - indice del checkbox: " + index + "\n";

            });//. children per accedere ai figli, l altro punto childrr per prender i checkbox checcati

            break;
        case 5: 
            _selector.find("input:checkbox[name=chk]").not(":checked")
                .each(
                    function(index,elem){
                        messGenerico += $(elem).val() + " - indice del checkbox: " + index + "\n";
                    }
                );
                
            break;
        case 6:
            messGenerico =  $("input[type=radio]:checked").val();
            break;

        case 7: 
            $(":radio:not(:checked)")
            .each(
                function(index,elem){
                    messGenerico += $(elem).val() + "\n";
                }
            );
            ;
            break;

        case 8:
            _selector.find("select").eq(1).children("option:selected")
            .each(function(index,elem){
                messGenerico += $(elem).val() + "\n";
            })
            break;
    }
    console.log(messGenerico);
}
function imposta(codice){
    switch (codice) {
        case 1:
            $("input[type=text]").val("Nuovo Valore");
            break;
    
        case 2:
            _selector.find("select").eq(0).val("2")
            
            break;
        
        case 3:
            $(":checkbox").val(["opzione1","opzione3"]);//QUADRE OBBLIGATORIE NEI CHECKBOX
            break;
        case 4:
            $(":radio").val(["no"]);
            break;
        case 5:
            _selector.find("select").eq(1).val(["2" , "3"])
            break;
    }
}