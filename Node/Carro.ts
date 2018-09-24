import {Veiculo} from './Veiculo'

export class Carro extends Veiculo {
    private numDePortas: number    

    constructor(modelo: string, numDePortas: number){
        super()
        this.modelo = modelo
        this.numDePortas = numDePortas
    }
}