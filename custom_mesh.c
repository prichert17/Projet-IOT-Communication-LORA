#include <string.h>
#include "custom_mesh.h" 

// CORRECCIÓN: Recibimos un puntero *payload
size_t create_custom_message(struct custom_mesh* msg, uint8_t src, uint8_t dest, uint8_t role, const uint8_t *payload, uint16_t payload_len) {
    
    // 1. Limpieza segura
    memset(msg, 0, sizeof(struct custom_mesh));

    // 2. Remplissage des champs
    msg->src = src;
    msg->dest = dest;
    msg->nb_saut = 4; 
    msg->role = role;

    // 3. Protección de tamaño
    if (payload_len > sizeof(msg->pb_payload)) {
        payload_len = sizeof(msg->pb_payload);
    }

    msg->taille = payload_len; 

    // 4. COPIA DE DATOS (Lo importante)
    // Verificamos que el puntero no sea NULL y el tamaño > 0
    if (payload != NULL && payload_len > 0) {
        // Usamos memcpy para copiar la cadena de texto
        memcpy(msg->pb_payload, payload, payload_len);
    }

    // 5. Calcul de la taille réelle
    size_t header_size = sizeof(struct custom_mesh) - sizeof(msg->pb_payload);
    return header_size + payload_len;
}


