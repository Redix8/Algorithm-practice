class Heap{
    constructor(compare){
        this.heap = []
        this.compare = compare
        this.length = this.heap.length        
    }
    push(item){
        this.heap.push(item)
        let idx = this.heap.length - 1        
        while(idx > 0 ){
            const parent = parseInt((idx-1) / 2)
            if(this.compare(this.heap[idx], this.heap[parent]) > 0){
                break
            }
            [this.heap[idx], this.heap[parent]] = [this.heap[parent], this.heap[idx]]
            idx = parent
        }
        this.length = this.heap.length
    }
    pop(){
        const head = this.heap.shift()
        if(this.heap.length){
            this.heap.unshift(this.heap.pop())
        }        
        let cur = 0
        while(true){
            const left = cur*2+1
            const right = cur*2+2
            if(left >= this.heap.length) break
            let next = cur
            if(this.compare(this.heap[next], this.heap[left]) > 0){
                next = left
            }
            if(right < this.heap.length && this.compare(this.heap[next], this.heap[right]) > 0){
                next = right
            }
            if(next === cur) break
            [this.heap[cur], this.heap[next]] = [this.heap[next], this.heap[cur]]
            cur = next        
        }
        this.length = this.heap.length
        return head        
    }
    head(){
        return this.heap[0]              
    }
}
