class Heap {
    constructor(_compare) {
        this.heap = [];
        this.compare = (arr, a, b) => {
            return _compare(arr[a], arr[b]) > 0;
        };
        this.length = this.heap.length;
    }

    swap(arr, idx1, idx2) {
        [arr[idx1], arr[idx2]] = [arr[idx2], arr[idx1]];
        return arr;
    }

    push(item) {
        let heap = this.heap;
        heap.push(item);
        let idx = heap.length - 1;
        while (idx > 0) {
            const parent = parseInt((idx - 1) / 2);
            if (this.compare(heap, idx, parent)) {
                break;
            }
            heap = this.swap(heap, idx, parent);
            idx = parent;
        }
        this.length = heap.length;
        this.heap = heap;
        console.log(heap, this.heap);
    }
    pop() {
        let heap = this.heap;
        if (heap.length > 1) {
            heap = this.swap(heap, 0, heap.length - 1);
        }
        const head = heap.pop();
        let cur = 0;

        while (true) {
            const left = cur * 2 + 1;
            const right = cur * 2 + 2;
            if (left >= heap.length) break;
            let next = cur;
            if (this.compare(heap, next, left)) {
                next = left;
            }
            if (right < heap.length && this.compare(heap, next, right)) {
                next = right;
            }
            if (next === cur) break;
            heap = this.swap(heap, cur, next);
            cur = next;
        }
        this.length = heap.length;
        this.heap = heap;

        return head;
    }
    head() {
        return this.heap[0];
    }
}
