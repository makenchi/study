"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
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
exports.Concesionaria = Concesionaria;
