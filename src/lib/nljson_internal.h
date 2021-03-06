#ifndef _NLJSON_INTERNAL_H_
#define _NLJSON_INTERNAL_H_

#include <nljson_config.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#include <netlink/msg.h>
#include <netlink/attr.h>

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

#define SET_ERR(error, code, fmt, ...) \
	do { \
		if (error) { \
			snprintf((error)->err_msg, sizeof((error)->err_msg), \
				 (fmt), ##__VA_ARGS__); \
			(error)->err_code = code; \
		} \
	} while (0)

#define SET_ERR_MSG(error, fmt, ...) SET_ERR((error), 0, (fmt), ##__VA_ARGS__)


/*
 * JSON key strings used in the JSON encoded nla streams and
 * policy files.
 */
#define DATA_TYPE_STR             ("data_type")
#define DATA_TYPE_STR_LEN         (sizeof(DATA_TYPE_STR) - 1)
#define ATTR_TYPE_STR             ("nla_type")
#define ATTR_TYPE_STR_LEN         (sizeof(ATTR_TYPE_STR) - 1)
#define POLICY_ATTR_TYPE_STR      ATTR_TYPE_STR
#define POLICY_ATTR_TYPE_STR_LEN  ATTR_TYPE_STR_LEN
#define LENGTH_STR                ("nla_len")
#define LENGTH_STR_LEN            (sizeof(LENGTH_STR) - 1)
#define POLICY_MAX_LENGTH_STR     ("maxlen")
#define POLICY_MAX_LENGTH_STR_LEN (sizeof(POLICY_MAX_LENGTH_STR) - 1)
#define POLICY_MIN_LENGTH_STR     ("minlen")
#define POLICY_MIN_LENGTH_STR_LEN (sizeof(POLICY_MIN_LENGTH_STR) - 1)
#define VALUE_STR                 ("value")
#define VALUE_STR_LEN             (sizeof(VALUE_STR) - 1)
#define POLICY_STR                ("nested")
#define POLICY_STR_LEN            (sizeof(POLICY_STR) - 1)
#define TS_STR                    ("timestamp")
#define TS_STR_LEN                (sizeof(TS_STR) - 1)

#define NLA_HDR_LEN 4

struct nljson_nla_policy {
	struct nla_policy *policy;
	char **id_to_str_map;
	struct nljson_nla_policy **nested;
	nljson_int_t max_attr_type;
	nljson_int_t max_nested_attr_type;
};

struct _nljson {
	struct nljson_nla_policy *policy;
	uint32_t encode_flags;
};

extern const char *data_type_strings[NLA_TYPE_MAX + 1];

#endif /*_NLJSON_INTERNAL_H_*/

