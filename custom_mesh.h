#ifndef CUSTOM_MESH_H
#define CUSTOM_MESH_H

#include <stdint.h>
#include <stddef.h> // Pour size_t
#include <stdbool.h>
// ID de notre nœud (C'est "nous")
#define MY_NODE_ID      0x22        

// Si tu envoies juste 0xFF sur un uint32, c'est 0x000000FF
#define BROADCAST_ID    0xFF
struct __attribute__((__packed__)) custom_mesh
{
  uint8_t dest;
  uint8_t src;
  uint8_t nb_saut;
  uint16_t taille;
  uint8_t role;
  uint8_t pb_payload[32];
};

// CORRECCIÓN: 'const uint8_t *payload' (Puntero a los datos)
size_t create_custom_message(struct custom_mesh* msg, uint8_t src, uint8_t dest, uint8_t role, const uint8_t *payload, uint16_t payload_len);

#endif
