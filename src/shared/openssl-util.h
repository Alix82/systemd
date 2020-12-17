/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include "macro.h"

#if HAVE_OPENSSL
#  include <openssl/pem.h>

DEFINE_TRIVIAL_CLEANUP_FUNC(X509*, X509_free);
DEFINE_TRIVIAL_CLEANUP_FUNC(X509_NAME*, X509_NAME_free);
DEFINE_TRIVIAL_CLEANUP_FUNC(EVP_PKEY_CTX*, EVP_PKEY_CTX_free);
DEFINE_TRIVIAL_CLEANUP_FUNC(EVP_CIPHER_CTX*, EVP_CIPHER_CTX_free);

int rsa_encrypt_bytes(EVP_PKEY *pkey, const void *decrypted_key, size_t decrypted_key_size, void **ret_encrypt_key, size_t *ret_encrypt_key_size);

int rsa_pkey_to_suitable_key_size(EVP_PKEY *pkey, size_t *ret_suitable_key_size);

#endif
