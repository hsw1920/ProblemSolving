func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var arr:[[Int]]=[]
    let i = arr1.count
    let j = arr1[0].count
    for q in 0..<i{
        var tmp:[Int]=[]
        for w in 0..<j{
            tmp.append(arr1[q][w]+arr2[q][w])
        }
        arr.append(tmp)
    }
    return arr
}