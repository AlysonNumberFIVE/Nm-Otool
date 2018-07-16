/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:34:40 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 11:44:09 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include <sys/stat.h>
# include <mach-o/loader.h>
# include <mach-o/swap.h>
# include "libft/libft.h"

void						special_letters(unsigned n_sect,
					unsigned int n_type);
int							arc_magic(unsigned char *content);
int							signature_check(unsigned char *content);
void						recursive_nm(unsigned char *content, size_t size,
					size_t count);
void						which(unsigned int n_type, unsigned int n_sect,
							unsigned int n_value);
int							is_64_or_32(struct mach_header *head);
int							read_file(void **content, size_t *size,
							char *filename);
void						symbols(void *content);
void						print_address_values(unsigned long long hex,
					int flag);
void						nm_64(struct mach_header *header, void *content);
void						nm_32(struct mach_header *header,
							void *content);
void						string_segment(void *content,
							struct symtab_command *tab);
void						which_is_it_again(int n_sect, int n_type);
struct symtab_command		*iterate_through_load_commands(struct
					load_command *comm, int command_num);
void						print_name(const char *name);
#endif
