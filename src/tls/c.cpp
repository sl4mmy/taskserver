#include <iostream>
#include <TLSClient.h>

int main (void)
{
  // A very basic TLS client, with X.509 authentication.
  TLSClient client;
  client.init ("pki/client.cert.pem");
  client.connect ("127.0.0.1", "5556");
  
  client.send ("This is a test.");

  std::string response;
  client.recv (response);
  std::cout << response << "\n";

  return 0;
}
