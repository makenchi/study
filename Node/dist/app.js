"use strict";
var Carro = /** @class */ (function () {
    function Carro(modelo, numDePortas) {
        this.velocidade = 0;
        this.modelo = modelo;
        this.numDePortas = numDePortas;
    }
    Carro.prototype.acelerar = function () {
        this.velocidade = this.velocidade + 10;
    };
    Carro.prototype.parar = function () {
        this.velocidade = 0;
    };
    Carro.prototype.mostraVelocidade = function () {
        return this.velocidade;
    };
    return Carro;
}());
var Concesionaria = /** @class */ (function () {
    function Concesionaria(endereco, listaCarros) {
        this.endereco = endereco;
        this.listaDeCarros = listaCarros;
    }
    Concesionaria.prototype.fornecerEndereco = function () {
        return this.endereco;
    };
    Concesionaria.prototype.mostrarListaDeCarros = function () {
        return this.listaDeCarros;
    };
    return Concesionaria;
}());
var Pessoa = /** @class */ (function () {
    function Pessoa(nomePessoa, carroP) {
        this.nome = nomePessoa;
        this.carroPreferido = carroP;
    }
    Pessoa.prototype.dizerNome = function () {
        return this.nome;
    };
    Pessoa.prototype.dizerCarroPreferido = function () {
        return this.carroPreferido;
    };
    Pessoa.prototype.comprarCarro = function (carroComprado) {
        this.carro = carroComprado;
    };
    Pessoa.prototype.dizerCarroQueTem = function () {
        return this.carro;
    };
    return Pessoa;
}());
/*criando os carro */
var carroA = new Carro('Batmovel', 2);
var carroB = new Carro('Bugre aranha', 4);
var carroC = new Carro('Uno', 2);
/*monta lista de carros*/
var listaDeCarros = [carroA, carroB, carroC];
/*Também pode ser escrito assim
let listaDeCarros: Array<Carro> = [carroA, carroB, carroC]*/
var concessionaria = new Concesionaria('Metrópolis', listaDeCarros);
console.log(concessionaria.mostrarListaDeCarros());
/*Comprar o carro */
var cliente = new Pessoa('Bruce Wayne', 'Batmovel');
concessionaria.mostrarListaDeCarros().map(function (carro) {
    if (carro['modelo'] == cliente.dizerCarroPreferido()) {
        cliente.comprarCarro(carro);
    }
});
console.log(cliente.dizerCarroQueTem());
