import {Veiculo} from './Veiculo'

export class Moto extends Veiculo{
    constructor(modelo: string){
        super()
        this.modelo = modelo
    }    
}