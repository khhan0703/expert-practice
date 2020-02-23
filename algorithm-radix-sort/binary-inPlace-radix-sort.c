/*
@startuml
start
note right
    **Binary In-place Radix Sort Algorithm**
    RadixSort(data, digit, startIdx, endIdx) 
    // first, call RadixSort(data, MSB, 0, lengthOfData-1)
end note

partition Do-Binary-Radix-Sort {
    :idxOf0 = startIdx
    idxOf1 = endIdx;
    repeat
        while (digit of data[idxOf0++] == 0) is (yes)
        endwhile (no)
        while (digit of data[idxOf1--] == 1) is (yes)
        endwhile (no)
        :swap(data[idxOf0], data[idxOf1]);
    repeat while (idxOf0 > idxOf1) is (no)
    -> yes;
    :startIdxOf0 = startIdx
    endIdxOf0 = idxOf0
    startIdxOf1 = idxOf1
    endIdxOf1 = endIdx;
}

if (digit == 1) then (yes)
else (no)
  :call RadixSort(data, digit-1, startIdxOf0, endIdxOf0);
  :call RadixSort(data, digit-1, startIdxOf1, endIdxOf1);
endif

end
note right
    return
end note
@enduml
*/

extern void print(int arr[], int n);
extern void print4bit(int arr[], int n);
int RADIX = 2;
int radixSort(int data[], int n, int digit, int startIdx, int endIdx)
{
    //print(arr, n);
    print4bit(data, n);
    int mask = 1<<(digit-1);
    register int idxOf0, idxOf1;
    int tmpData;
    while (1)
    {
        for (idxOf0 = startIdx;idxOf0 <= endIdx; idxOf0++)
        { 
            if((mask & data[idxOf0]) == mask) break;
        }
        for (idxOf1 = endIdx;idxOf0 >= startIdx; idxOf1--)
        { 
            if((mask & data[idxOf1]) == 0) break;
        }
        if (idxOf0 > endIdx || idxOf1 < startIdx || idxOf0 > idxOf1)
        {
            idxOf0--;
            idxOf1++;
            break;
        }
        else
        {
            tmpData = data[idxOf0];
            data[idxOf0] = data[idxOf1];
            data[idxOf1] = tmpData;
        }
    }
    int startIdxOf0 = startIdx, endIdxOf0 = idxOf0;
    int startIdxOf1 = idxOf1, endIdxOf1 = endIdx;
    if (digit == 1) 
    {
        return 0;
    }
    else 
    {
       radixSort(data, endIdxOf0-startIdxOf0+1, digit-1, startIdxOf0, endIdxOf0);
       radixSort(data, endIdxOf1-startIdxOf1+1, digit-1, startIdxOf1, endIdxOf1);
    }
    print4bit(data, n);
    return 0;
}