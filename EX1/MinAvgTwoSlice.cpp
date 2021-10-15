// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A){
    int n = A.size();
    int izq_index, min_izq_index;
    double AVG, min_avg, avgo2, avg_prev;
    vector<int> prefx_Sum(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        prefx_Sum[i] = A[i-1] + prefx_Sum[i-1];
    }
    izq_index = min_izq_index = 0;
    AVG = min_avg = (A[0] + A[1]) / 2.0;
    
    for (int i = 2; i < n; i ++) {
        int v1=i - izq_index + 1;
        avg_prev = ((double) prefx_Sum[i + 1] - prefx_Sum[izq_index]) / (v1);
        avgo2 = (A[i - 1] + A[i]) / 2.0;
        if (avgo2 < avg_prev) {
            AVG = avgo2;
            izq_index = i - 1;
        }
        else{
            AVG = avg_prev;
        }    
        if (AVG < min_avg) {
            min_avg = AVG;
            min_izq_index = izq_index;
        }
    }
        
    return min_izq_index;
}