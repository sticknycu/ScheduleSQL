#include "addEntry.h"
#include <string.h>
#include "../../../json-c/json.h"
#include <stdio.h>

void addEntry(char *fileName, char *entry, char *data) {



    /*json_object *my_array;
    my_array = json_object_new_array();
    json_object_array_add(my_array, json_object_new_int(1));
    json_object_array_add(my_array, json_object_new_int(2));
    json_object_array_add(my_array, json_object_new_int(3));
    json_object_array_put_idx(my_array, 4, json_object_new_int(5));
    printf("my_array=\n");
    int i;
    for(i=0; i < json_object_array_length(my_array); i++) {
        json_object *obj = json_object_array_get_idx(my_array, i);
        printf("\t[%d]=%s\n", i, json_object_to_json_string(obj));
    }
    printf("my_array.to_string()=%s\n", json_object_to_json_string(my_array));

    //json_object_arra(my_array);
    json_object_to_file(fileName, my_array);*/
}