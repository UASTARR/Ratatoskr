/**
 * @Copyright Alexander Williams-Letondre 2024-12-28
 */

#include "main.hpp"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "MQTTClient.h"


/** HELPERS *****************************************************************************/

class Main
{
  public:
    Main() = default;

    /** Message callback */
    static int messageArrived(
        void *context,char *topicName, int topicLen, MQTTClient_message *message
    )
    {
        printf("Message arrived %s\n", (char*)message->payload);
        return 0;
    }

  private:
};


/** ENTRY *******************************************************************************/

int main() {
    printf("Starting loopback example...\n");

    MQTTClient client;
    MQTTClient_create(&client, "tcp://localhost:1883", "client", MQTTCLIENT_PERSISTENCE_NONE, NULL);

    int32_t setCallbackRes = MQTTClient_setCallbacks(
        client, NULL, NULL, Main::messageArrived, NULL
    );

    printf("callback established: %d\n", setCallbackRes);

    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_SSLOptions ssl_opts = MQTTClient_SSLOptions_initializer;
    ssl_opts.enableServerCertAuth = 0;

    // TODO: Review github.com/eclipse/paho.mqtt.c/blob/master/src/samples/paho_c_sub.c
    ssl_opts.verify = 1;
    ssl_opts.CApath = NULL;
    ssl_opts.keyStore = NULL;
    ssl_opts.trustStore = NULL;
    ssl_opts.privateKey = NULL;
    ssl_opts.privateKeyPassword = NULL;
    ssl_opts.enabledCipherSuites = NULL;

    // Use TLS for a secure conenction
    conn_opts.ssl = &ssl_opts;
    conn_opts.keepAliveInterval = 10;
    conn_opts.cleansession = 1;

    // Use credentaials created with the cluster (TODO: ???)
    // conn_opts.username = "<your_username>";
    // conn_opts.password = "<your_password>";
    int32_t connectRes = MQTTClient_connect(client, &conn_opts);
    printf("is connected %d \n", connectRes);

    // the topic where you publish to and subscribe to

    const char* topic = "/diagnostics";
    MQTTClient_subscribe(client, topic, MQTTREASONCODE_GRANTED_QOS_1);
    printf("subscribed to %s \n", topic);

    // payload the content of your message

    char* payload = "Hello, World!";
    int payloadlen = strlen(payload);

    MQTTClient_deliveryToken dt;
    MQTTClient_publish(
        client, topic, payloadlen, payload, MQTTREASONCODE_GRANTED_QOS_1, 0, &dt
    );

    printf("published to %s \n", topic);

    // after this time, unsubscribe, disconnect and destroy the client to terminate every process

    int timeout = 100;
    MQTTClient_unsubscribe(client, topic);
    MQTTClient_disconnect(client, timeout);
    MQTTClient_destroy(&client);

    return 0;
}
