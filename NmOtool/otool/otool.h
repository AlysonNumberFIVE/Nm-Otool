/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:54:02 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/16 12:15:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_H
# define OTOOL_H

# include <sys/mman.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <mach-o/loader.h>
# include <stdio.h>

void						print_mem_val(unsigned long long hex);
int							hex_number_length(size_t number);
void						intro_info(char *filename);
int							is_dynamic_lib(unsigned char *content);
int							read_file(void **content, size_t *size,
							char *filename);
void						otool(void *content, char *filename);
int							is_64_or_32(struct mach_header *head);
struct segment_command_64	*iterate_to_textseg(
							struct load_command *comm,
							int command_num,
							size_t count);
void						print_hex_value(unsigned long long hex);
void						put_otool_hex(unsigned long long hex);
void						print_mem_val(unsigned long long hex);
void						otool_32(struct mach_header *header, void *content);
void						otool_64(struct mach_header *header, void *content);
void						print_section(void *content,
							size_t start, size_t limit, size_t size);

#endif
