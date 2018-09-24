"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
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
exports.Carro = Carro;
