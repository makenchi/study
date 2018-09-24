"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
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
exports.Pessoa = Pessoa;
