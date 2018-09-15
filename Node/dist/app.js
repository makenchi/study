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
var Consesionaria = /** @class */ (function () {
    function Consesionaria(endereco) {
        this.endereco = endereco;
    }
    Consesionaria.prototype.fornecerEndereco = function () {
        return this.endereco;
    };
    Consesionaria.prototype.mostrarListaDeCarros = function () {
        return this.listaDeCarros;
    };
    return Consesionaria;
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
        return this.carro;
    };
    Pessoa.prototype.comprarCarro = function (carroComprado) {
        this.carro = carroComprado;
    };
    Pessoa.prototype.dizerCarroQueTem = function () {
        return this.carro;
    };
    return Pessoa;
}());
