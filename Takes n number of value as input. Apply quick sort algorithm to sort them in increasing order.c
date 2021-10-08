#include<stdio.h>

void swap(int* first_operant, int* second_operant){
	int collect = *first_operant;
	*first_operant = *second_operant;
	*second_operant = collect;
}


int divider_into_part (int array_to_be_sort[], int low, int high){
	int pivot_eliemnt = array_to_be_sort[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++){

		if (array_to_be_sort[j] < pivot_eliemnt)
		{
			i++;
			swap(&array_to_be_sort[i], &array_to_be_sort[j]);
		}
	}
	swap(&array_to_be_sort[i + 1], &array_to_be_sort[high]);
	return (i + 1);
}
int divider_into_part (int array_to_be_sort[], int low, int high){
	int pivot_eliemnt = array_to_be_sort[low];
	int i = (high - 1);

	for (int j = high; j >= low- 1; j--){

		if (array_to_be_sort[j] < pivot_eliemnt)
		{
			i++;
			swap(&array_to_be_sort[i], &array_to_be_sort[j]);
		}
	}
	swap(&array_to_be_sort[i + 1], &array_to_be_sort[low]);
	return (i + 1);
}


void quick_sort(int array_to_be_sort[], int low, int high){
	if (low < high){
		int pi = divider_into_part(array_to_be_sort, low, high);
		quick_sort(array_to_be_sort, low, pi - 1);
		quick_sort(array_to_be_sort, pi + 1, high);
	}
}

void print_array(int array_to_be_sort[], int size){
	int itaration;
	for (itaration = 0; itaration < size; itaration++){
        printf("%d ", array_to_be_sort[itaration]);
	}
	printf("\n");
}


int main(){
	int array_to_be_sort[10];

    printf("Enter the number to sort: \n");

    for(int index = 0; index < 10; ++index) {
        scanf("%d", &array_to_be_sort[index]);
    }


	int n = sizeof(array_to_be_sort)/sizeof(array_to_be_sort[0]);
	quick_sort(array_to_be_sort, 0, n-1);
	printf("Sorted array: \n");
	print_array(array_to_be_sort, n);
	return 0;
}
