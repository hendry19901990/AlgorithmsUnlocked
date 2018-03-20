/** 
 * procedure linearsearch(x : integer, a1,a2,a3,a4,a5....,aN : list elements)
 * i := 1;
 * while  i <= n AND x != a[i]
 * {
 *      i := i + 1;
 * }
 *      if i <= n then location := i
 *      else location := 0
 *  return location
 * -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * procedure binarysearch(x : integer, a1,a2,a3,a4,a5.......aN : sorted list)
 *      i := 1
 *      j := n
 * while i < j
 * {
 *      m := [(i + j) / 2]
 *      if x > a[m] then i := m + 1
 *      else j:= m
 *      if x := a[i] then location := i
 *      else location := 0
 * }
 * return location
 * ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * procedure bubblesort(a1,a2,a3,......aN : real numbers with index n >= 2)
 * {
 *      for i := 1 to n - 1
 *          for j := 1 to n - i
 *              if a[j] > a[j + 1] then swap a[j] -> a[j + 1]
 * }
 * procedure insertionsort(a1,a2,a3,......aN : real numbers with index n >= 2)
 * {
 *      for j := 2 to n
 *          i := 1
 *              while a[j] > a[i]
 *                  i := i + 1
 *                  m : = a[j]
 *                      for k := 0 to j - i - 1
 *                          a[j - k] = a[j - k - 1]
 *                      a[j] := m
 * }
 * ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * prcedure greedycoinchange(c1,c2,c3,c4,c5........cN : value of denoiminations of a coin)
 * {
 *      procedure sortcoins( sort --> coins c1,c2,c3,c4,c5.....cN sudh that c1 < c2 < c3 < c4 < c5 < c6 < ............. < cN) { sort }
 *          for i := 1 to r
 *              di := 0
 *                  while n >= c[i]
 *                      di := di + 1
 *                      n := n - c[i]
 * 
 * }
 * ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * procedure greedyschedule(s1 <= s2 <= s3 <= s4 <= ........ <= sN : start times of talks ;; e1 <= e2 <= e3 <= e4 <= ........... <= eN : end times of the talks)
 * {
 *      S := [sym:phi]
 *      sort talks by finishing time
 *          for j := 1 to n
 *              if talk[j] is compatible with jobs in Set S then 
 *                  S := S U { talk[j] }
 *          return S
 * }
 * ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * procedure selectionsort (a , n)
 * // sort the array a[1 : n] into nondecreasding order
 * {
 *      for i := 1 to n
 *      {
 *          j := i;
 *          for k := i + 1 to n do 
 *              if a[k] < a[j] then j := k
 *          t := a[i]; a[i] := a[j]; a[j] := t 
 *      }
 * }
 * ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * */



























