"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
/*Importando os módulos*/
var Carro_1 = require("./Carro");
var Concessionaria_1 = require("./Concessionaria");
var Pessoa_1 = require("./Pessoa");
/*criando os carro*/
var carroA = new Carro_1.Carro('Batmovel', 2);
var carroB = new Carro_1.Carro('Bugre aranha', 4);
var carroC = new Carro_1.Carro('Uno', 2);
/*monta lista de carros*/
var listaDeCarros = [carroA, carroB, carroC];
/*Também pode ser escrito assim
let listaDeCarros: Array<Carro> = [carroA, carroB, carroC]*/
var concessionaria = new Concessionaria_1.Concesionaria('Metrópolis', listaDeCarros);
console.log(concessionaria.mostrarListaDeCarros());
/*Comprar o carro */
var cliente = new Pessoa_1.Pessoa('Bruce Wayne', 'Batmovel');
concessionaria.mostrarListaDeCarros().map(function (carro) {
    if (carro['modelo'] == cliente.dizerCarroPreferido()) {
        cliente.comprarCarro(carro);
    }
});
console.log(cliente.dizerCarroQueTem());
console.log(concessionaria.fornecerHoraDeFunc());
